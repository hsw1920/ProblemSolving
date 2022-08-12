import Foundation

func solution(_ n:Int) -> Int {
    var x = n
    var a:[Int] = []
    while x > 0 {
        a.append(x%3)
        x/=3
    }
    var k = 1
    var res = 0
    a.reversed().map {
        res += $0*k
        k*=3
    }
    return res
}