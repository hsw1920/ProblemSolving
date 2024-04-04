import Foundation

var dict: [Int:Int] = [:]
var set = Set<Int>()
var cnt = 0
func solution(_ topping:[Int]) -> Int {    
    topping.forEach {
        dict[$0, default: 0] += 1
    }
    
    topping.forEach {
        set.insert($0)
        dict[$0, default: 0] -= 1
        if dict[$0]! <= 0 { dict[$0] = nil}
        if set.count == dict.count { cnt += 1 }
    }
    
    return cnt
}