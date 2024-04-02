import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var res: [Int] = []
    var tmp: [Int] = []
    for i in 0..<score.count {
        var cur = score[i]
        tmp.append(cur)
        
        tmp.sort(by: >)
        if tmp.count < k {
            res.append(tmp.last!)
        } else {
            res.append(tmp[k-1])
        }   
    }
    
    return res
}