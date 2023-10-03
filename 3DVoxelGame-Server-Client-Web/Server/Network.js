const Player = require("./Player");
const World = require("./World/World.js");
class Network {
    static players = [];
    static world = null;

    static Init() {
        Network.world = new World("TestWorld");
        console.log("Initialized Network Class");
    }

    static OnSocketConnected(socket) {
        var player = new Player(this, socket);
        Network.players.push(player);

        socket.on("GetPlayerList", () => {
            var list = [];
            for (var i = 0; i < Network.players.length; i++)
                list.push(Network.players[i].user_id);
            socket.emit("SetPlayerList", list);
        });

        socket.on("GetChunk", (x, z) => {
            var chunk = Network.world.GetChunk(x, z);
            if (!chunk)
                chunk = Network.world.CreateChunk(x, z);

            socket.emit("ReceivedChunkData", x, z, chunk.block_data);
        });

        socket.on("SetPosition", (x, y, z) => {
            player.SetPosition(x, y, z);
            Network.BroadcastWithException("SetPlayerPosition", [player.user_id, x, y, z], player.user_id);
        })

        socket.on("disconnect", () => {
            Network.OnSocketDisconnected(player);
        });
    }

    static Broadcast(type, data) {
        for (var i = 0; i < Network.players.length; i++) {
            var player = Network.players[i];
            var socket = player.socket;

            socket.emit(type, ...data);
        }
    }

    static BroadcastWithException(type, data, user_id) {
        for (var i = 0; i < Network.players.length; i++) {
            var player = Network.players[i];
            var socket = player.socket;

            if (player.user_id != user_id)
                socket.emit(type, ...data);
        }
    }

    static OnSocketDisconnected(player) {
        var index = Network.players.indexOf(player);

        if (index >= 0) {
            Network.players.splice(index, 1);
        }
    }
}

module.exports = Network;