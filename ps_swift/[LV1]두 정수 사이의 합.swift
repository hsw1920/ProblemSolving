func solution(_ a:Int, _ b:Int) -> Int64 {
    var sum:Int64 = 0
    var n:Int64 = abs(Int64(b)-Int64(a))
    var k:Int64 = Int64(b)+Int64(a)
    return k*(n+1)/2
}