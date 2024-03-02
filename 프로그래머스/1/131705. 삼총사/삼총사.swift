import Foundation
// 3명 정수 번호 더했을 때 0되면 삼총사임

func solution(_ number:[Int]) -> Int {
    
    // 13^3
    var res = 0
    for i in 0..<number.count {
        for j in (i+1)..<number.count {
            for k in (j+1)..<number.count {
                if number[i]+number[j]+number[k] == 0 {
                    res += 1
                }
            }
        }   
    }
    
    return res
}