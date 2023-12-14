import Foundation

func solution(_ n:Int, _ m:Int, _ section:[Int]) -> Int {
var wall = section
    var arr = Array(repeating: 1, count: n + 1)
    var range = m
    var result = 0
    var idx = 0
    for i in wall {
        arr[i] = 0
    }
    while idx < arr.count {
        if arr[idx] == 0 {
            result += 1
            idx += range
        } else {
            idx += 1
        }
    }
    return result
}