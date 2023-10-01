class World {
    name = "";

    chunks = [];

    rotation = 0;

    Init() {
        this.chunks = new Map();
        var chunk = new Chunk(0, 0);
        this.chunks.set("0,0", chunk);
    }
    Update() {
        var chunk = this.chunks.get("0,0");
        chunk.Update();
    }
    Draw() {
        Game.chunk_shader.Start();
        var matrix1 = mat4.create();
        var matrix2 = mat4.create();
        var matrix3 = mat4.create();
        matrix1 = mat4.perspective(matrix1, Mathf.ToRadians(80), Display.GetAspectRatio(), 0.01, 1000);
        matrix2 = mat4.translate(matrix2, matrix2, [0, 0, -5]);
        matrix3 = mat4.rotate(matrix3, matrix3, Mathf.ToRadians(this.rotation), [0, 1, 0]);
        Game.chunk_shader.LoadMatrix4x4(Game.chunk_shader.projection_matrix_location, matrix1);
        Game.chunk_shader.LoadMatrix4x4(Game.chunk_shader.view_matrix_location, matrix2);
        Game.chunk_shader.LoadMatrix4x4(Game.chunk_shader.transformation_matrix_location, matrix3);

        this.rotation = this.rotation + 1;
        var chunk = this.chunks.get("0,0");
        chunk.Draw();
        Game.chunk_shader.Stop();
    }
}