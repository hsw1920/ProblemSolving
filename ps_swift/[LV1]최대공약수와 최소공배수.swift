func gcd(_ x:Int, _ y:Int) -> Int{
    if x%y==0 {
        return min(x,y)
    }
    return gcd(y,x%y)
}
func solution(_ n:Int, _ m:Int) -> [Int] {
    // 최소공배수 = a*b/최대공약수
    
    return [gcd(n,m),n*m/gcd(n,m)]
}