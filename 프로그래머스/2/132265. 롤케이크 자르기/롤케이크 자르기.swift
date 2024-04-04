import Foundation

var dict: [Int:Int] = [:]
var set = Set<Int>()
var cnt = 0
func solution(_ topping:[Int]) -> Int {    
    topping.forEach {
        guard let a = dict[$0] else {
            dict[$0] = 1
            return 
        }
        dict[$0]! += 1
    }
    
    topping.forEach {
        set.insert($0)
        
        if dict[$0] != nil {
            dict[$0]! -= 1
            if dict[$0]! == 0 {
                dict[$0] = nil
            }
        }
        
        if set.count == dict.count {
            cnt += 1
        }
    }
    
    return cnt
}