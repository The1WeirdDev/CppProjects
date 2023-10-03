class Display {
    static Init() {
        gl.clearColor(0.5, 0.5, 0.5, 1.0);
        gl.cullFace(gl.FRONT)
        gl.enable(gl.DEPTH_TEST);
        //gl.enable(gl.CULL_FACE);
    }
    static Update() {
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    }

    static GetAspectRatio() {
        return innerWidth / innerHeight;
    }
}