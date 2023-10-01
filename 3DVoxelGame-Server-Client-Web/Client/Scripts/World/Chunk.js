class Chunk {
    x = 0;
    z = 0;

    mesh = null;

    constructor(x, z) {
        this.x = x;
        this.z = z;
        this.mesh = new BasicMesh();
        this.mesh.CreateMesh([0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0], [0, 1, 2, 2, 1, 3]);
    }

    Update() {

    }

    Draw() {
        this.mesh.Draw();
    }
}