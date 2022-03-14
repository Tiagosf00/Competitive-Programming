// Apply linear transformation (p -> q) to r.
point linear_transformation(point p0, point p1, point q0, point q1, point r) {
    point dp = p1-p0, dq = q1-q0, num((dp^dq), (dp^dq));
    return q0 + point((r-p0)^(num), (r-p0)*(num))/(dp*dp);
}