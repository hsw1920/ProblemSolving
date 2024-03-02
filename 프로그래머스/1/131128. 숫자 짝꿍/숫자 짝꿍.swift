import Foundation

// 정수
// X,Y의 임의 자리에서 나타나는 정수중 짝지을수있는 숫자
// 짝 못지으면 -1

func solution(_ X:String, _ Y:String) -> String {
    var dictX: [String: Int] = [:]
    var dictY: [String: Int] = [:]
    var nums = [String]()
    
    for x in X.map{String($0)} {
        dictX[x] = (dictX[x] ?? 0) + 1
    }
    
    for y in Y.map{String($0)} {
        dictY[y] = (dictY[y] ?? 0) + 1
    }
    
    for key in dictX.keys {
        nums += Array(repeating: key, count: 
                      min((dictX[key] ?? 0), (dictY[key] ?? 0)))
    }
    
    if nums.isEmpty { return "-1" }
    if nums.filter { $0 == "0" }.count == nums.count { return "0" }
    return nums.sorted(by: >).joined()
}