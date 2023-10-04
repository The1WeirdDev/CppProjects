const WorldType = {
    Client: 0,
    Server:1,
}

class World {
    name = "";

    chunks = [];
    blocks = [];

    texture_size = 16 / 256;

    world_type = null;

    constructor(type) {
        this.world_type = type;
        this.AddBlock(new Block("Air", false, 0, 0, 0, 0, 0, 0));
        this.AddBlock(new Block("Grass", false, 0, 2, 1, 1, 1, 1));
        this.AddBlock(new Block("Stone", false, 3, 3, 3, 3, 3, 3));
    }

    AddBlock(block) {
        this.blocks.push(block);
    }

    GetBlockFromId(id) {
        return this.blocks[id];
    }
}