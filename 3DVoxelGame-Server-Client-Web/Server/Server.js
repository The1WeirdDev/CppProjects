const express = require("express");
const fs = require("fs");

const server = express();
const port = 80;

server.listen(port, (err, data) => {
    if (err) {
        console.log(`Error listening on port ${port} because of : ${error}`);
    } else {
        console.log(`Listening on port ${port}`);
    }
});

server.get("*", (req, res) => {
    var location = req.url;
    if (location == "/")
        location = "Client/Index.html";

    if (location.startsWith("/"))
        location = location.slice(1);

    SendFileToUser(location, res);
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