import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var k = d.sorted()
    var b = budget
    var cnt = 0
    for i in 0..<k.count {
        if b - k[i] >= 0 {
            cnt+=1
            b-=k[i]
        }
        else {
            return cnt
        }
    }
    return cnt
}