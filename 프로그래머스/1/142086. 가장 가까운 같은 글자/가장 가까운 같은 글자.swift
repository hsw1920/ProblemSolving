import Foundation

func solution(_ s:String) -> [Int] {
    var arr = s.map{String($0)}
    var ret: [Int] = []
    var dict: [String:Int] = [:]
    for i in 0..<s.count {
        var cur = arr[i]
        ret.append(-1)
        guard let num = dict[cur] else { 
            dict[cur]=i
            continue
        }
        ret[i]=i-num
        dict[cur]=i
    }
    
    return ret
}