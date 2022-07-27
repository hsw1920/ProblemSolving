import Foundation

func solution(_ n:Int64) -> Int64 {
    var k = Int64(sqrt(Double(n)))
    return n==k*k ? (k+1)*(k+1) : -1
}