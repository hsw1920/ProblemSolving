import Foundation

func solution(_ keymap:[String], _ targets:[String]) -> [Int] {
    var dict: [String:Int] = [:]
    var res: [Int] = []
    var keymap = keymap.map{$0.map{String($0)}}
    for i in keymap {
        for j in i {
            if dict[j] == nil {
                dict[j] = i.firstIndex(of: j)! + 1
            } else {
                dict[j] = min(dict[j]!, i.firstIndex(of: j)!+1)
            }
        
        }
    }
        for i in targets {
            var sum = 0
            
            for j in i.map{String($0)} {
                if dict[j] == nil {
                    sum = -1
                    break
                } else {
                    sum+=dict[j]!
                }
            }
            res.append(sum)
        }
    
    
    return res
}