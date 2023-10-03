class Frustom{
    static IsPointInsideViewFrustom(x, y, z, matrix){
        var p4d = new Vector4(x, y, z, 1.0);
        var clip_space_position = Vector4.MultiplyMatrixByVector(matrix, p4d);

        //&&(clip_space_position.y <= clip_space_position.w) &&(clip_space_position.y >= -clip_space_position.w)
        return ((clip_space_position.x <= clip_space_position.w) && (clip_space_position.x >= -clip_space_position.w) && (clip_space_position.z <= clip_space_position.w) && (clip_space_position.z >= -clip_space_position.w));

    }
}