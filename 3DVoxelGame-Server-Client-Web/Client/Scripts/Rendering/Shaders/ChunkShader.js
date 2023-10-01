class ChunkShader extends Shader {
    constructor() {
        super();
        var vertex_data = `precision mediump float; \nattribute vec3 position;\n uniform mat4 projection_matrix; uniform mat4 view_matrix; uniform mat4 transformation_matrix; void main(){ gl_Position = projection_matrix * view_matrix * transformation_matrix * vec4(position, 1.0); } `;
        var fragment_data = `precision mediump float; \nvoid main(){ gl_FragColor = vec4(1.0, 0.0, 1.0, 1.0); }`;
        this.Create(vertex_data, fragment_data);

        this.projection_matrix_location = this.GetUniformLocation("projection_matrix");
        this.view_matrix_location = this.GetUniformLocation("view_matrix");
        this.transformation_matrix_location = this.GetUniformLocation("transformation_matrix");
    }
}