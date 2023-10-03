const Chunk = require("./Chunk/Chunk.js");
const SimplexNoise = require("./../Libs/SimplexNoise");
class World {
    chunks = null;
    simplex = null;

    name = "";
    constructor(name) {
        this.name = name;

        this.simplex = new SimplexNoise(Math);
        this.chunks = new Map();
    }

    GetChunk(x, z) {
        var chunk = this.chunks.get(`${x},${z}`);
        return chunk;
    }

    CreateChunk(x, z) {
        var chunk = new Chunk(this, x, z);
        this.chunks.set(`${x},${z}`, chunk);
        chunk.GenerateWorldData();
        return chunk;
    }
}
module.exports = World;