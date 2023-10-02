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