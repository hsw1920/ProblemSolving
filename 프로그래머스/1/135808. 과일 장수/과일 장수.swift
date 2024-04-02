import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    var v = score.sorted(by:>)
    var cnt = v.count / m
    var idx = m-1
    var res = 0
    for i in 0..<cnt {
        res += (v[idx]*m)
        idx += m
    }
    
    return res
}