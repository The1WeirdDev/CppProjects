class Networking {
    static socket = null;

    static players = [];

    static Init() {
        Networking.socket = io(window.location.origin);

        Networking.players = [];
        Networking.socket.on("connect", () => {
            Networking.OnConnected();

            Networking.socket.on("SetPlayerList", (players) => {
                for (var i = 0; i < players.length; i++) {
                    console.log(players[i]);
                    var player = new NonLocalPlayer(players[i]);
                    Networking.players.push(player);
                }
            })

            Networking.socket.on("SetPlayerPosition", (id, x, y, z) => {
                var player = Networking.GetPlayerFromUserId(id);

                if (player) {
                    console.log("Setting position");
                    player.SetPosition(x, y, z);
                } else {
                    console.log("Coudlnt get player with id of " + id);
                }
            });

            Networking.socket.on("disconnect", () => {
                Networking.OnDisconnect();
            });
        });
    }

    static GetPlayerFromUserId(id) {
        for (var i = 0; i < Networking.players.length; i++) {
            var player = Networking.players[i];
            if (player.user_id == id)
                return player;
        }

        return null;
    }

    static SendPacket(type, data) {
        //Pass data as an array
        //The array will be unpacked into multiple elements
        Networking.socket.emit(type, ...data);
    }

    static OnConnected() {
        Networking.SendPacket("GetPlayerList", []);

        Networking.socket.on("ReceivedChunkData", (x, z, data) => {
            Game.world.ReceivedChunk(x, z, data);
        });
    }

    static OnDisconnect() {

    }

    static Draw() {
        //Game.non_local_player_shader.Start();
        for (var i = 0; i < Networking.players.length; i++) {
            var player = Networking.players[i];
            if (player)
                player.Draw();
        }
        //Game.non_local_player_shader.Start();
    }
}