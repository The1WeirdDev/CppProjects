class NonLocalPlayer extends Entity {
    user_id = null;
    position = null;

    player_mesh = null;
    transformation_matrix = null;

    constructor(user_id) {
        super();
        this.user_id = user_id;
        this.position = new Vector3();

        this.player_mesh = new PlayerMesh();

        this.player_mesh.CreateMesh([
            0, 0, 0,
            0, 1, 0,
            1, 0, 0,
            1, 1, 0
        ], [0, 1, 2, 2, 1, 3]);
    }

    Update() { }
    Draw() {
        this.player_mesh.Draw();
    }

    SetPosition(x, y, z) {
        this.position.x = x;
        this.position.y = y;
        this.position.z = z;

        this.transformation_matrix = mat4.create();
        this.transformation_matrix = mat4.translate(transformation_matrix, transformation_matrix, [this.position.x, this.position.y, this.position.z]);
    }

    GetTransformationMatrix() {
        return this.transformation_matrix;
    }
}