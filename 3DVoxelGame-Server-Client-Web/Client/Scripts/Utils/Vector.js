class Vector2 {
    x = 0;
    y = 0;

    Vector2(x = 0, y = 0) {
        this.x = x;
        this.y = y;
    }

    GetMagnitude() {
        return Math.sqrt((this.x * this.x) + (this.y * this.y));
    }
}
class Vector3 {
    x = 0;
    y = 0;
    z = 0;

    Vector2(x = 0, y = 0, z = 0) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    GetMagnitude() {
        return Math.sqrt((this.x * this.x) + (this.y * this.y) + (this.z * this.z));
    }
}
class Vector4 {
    x = 0;
    y = 0;
    z = 0;
    w = 0;

    Vector2(x = 0, y = 0, z = 0, w = 0) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    static MultiplyMatrixByVector(matrix, vector) {
        var vec = new Vector4();
        vec.x = (vector.x * matrix[(4 * 0) + 0]) + (vector.y * matrix[(4 * 0) + 0]);
        return vec;
    }

    GetMagnitude() {
        return Math.sqrt((this.x * this.x) + (this.y * this.y) + (this.z * this.z) + (this.w * this.w));
    }
}