class BasicMesh extends Mesh {
    CreateMesh(vertices, texture_coords, indices) {
        this.vao_id = gl.createVertexArray();
        this.vbo_id = gl.createBuffer();
        this.tbo_id = gl.createBuffer();
        this.ebo_id = gl.createBuffer();
        gl.bindVertexArray(this.vao_id);

        //Vertices
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vbo_id);
        gl.bufferData(
            gl.ARRAY_BUFFER,
            new Float32Array(vertices),
            gl.STATIC_DRAW
        );
        gl.enableVertexAttribArray(0);
        gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 0, 0);

        //Texture Coords
        gl.bindBuffer(gl.ARRAY_BUFFER, this.tbo_id);
        gl.bufferData(
            gl.ARRAY_BUFFER,
            new Float32Array(texture_coords),
            gl.STATIC_DRAW
        );
        gl.enableVertexAttribArray(1);
        gl.vertexAttribPointer(1, 2, gl.FLOAT, false, 0, 0);

        //Indices
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.ebo_id);
        gl.bufferData(
            gl.ELEMENT_ARRAY_BUFFER,
            new Uint16Array(indices),
            gl.STATIC_DRAW
        );

        gl.bindVertexArray(null);

        this.index_count = indices.length;
        this.created = true;
    }

    Draw() {
        if (!this.created) return;

        gl.bindVertexArray(this.vao_id);

        gl.enableVertexAttribArray(0);
        gl.enableVertexAttribArray(1);
        gl.drawElements(gl.TRIANGLES, this.index_count, gl.UNSIGNED_SHORT, 0);
    }

    CleanUp() {
        gl.bindVertexArray(null);
        gl.deleteBuffer(this.vbo_id);
        gl.deleteBuffer(this.tbo_id);
        gl.deleteBuffer(this.ebo_id);
        gl.deleteVertexArray(this.vao_id);
        this.created = false;
    }
}