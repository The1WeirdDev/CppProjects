const express = require("express");
const http = require("http");
const fs = require("fs");
const socket_io = require("socket.io");

const app = express();
const server = http.createServer(app);
const io = socket_io(server);
const port = 7777;

const Network = require("./Network");

server.listen(port, (err, data) => {
    if (err) {
        console.log(`Error listening on port ${port} because of : ${error}`);
    } else {
        console.log(`Listening on port ${port}`);
        Network.Init();
    }
});

app.get("*", (req, res) => {
    var location = req.url;
    if (location == "/")
        location = "Client/Index.html";

    if (location.startsWith("/") && !location.startsWith("/socket"))
        location = location.slice(1);

    SendFileToUser(location, res);
});

io.on("connect", (socket) => {
    Network.OnSocketConnected(socket);
});

function SendFileToUser(location, res) {
    try {
        const headers = { "Content-Type": "text/html" };
        fs.readFile(location, (err, data) => {
            if (err) {
                res.writeHead(404, headers);
                res.write("<html><h1>error 404 page not found</h1></html>");
            } else {
                res.writeHead(200, headers);
                res.write(data);
            }
            res.end();
        });
    } catch (exception) {

    }
}