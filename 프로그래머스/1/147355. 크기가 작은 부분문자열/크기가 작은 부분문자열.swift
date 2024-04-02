import Foundation

func solution(_ t:String, _ p:String) -> Int {
    // t와 p가 주어짐
    // t중에서 p길이와 동일한 문자열을 모두 구한다.
    // 해당 문자열과 p를 모두 비교해서 res++
    var res = 0
    var arr = t.map{$0}
    for i in 0..<t.count-p.count+1 {
        var tmp = arr[i..<i+p.count].map{String($0)}.joined()
        if tmp <= p {
            res+=1
        }
    }

    return res
}