import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    // 그냥정렬 -> O(N*logN)
    // var v = score.sorted(by:>)
    // var cnt = v.count / m
    // var idx = m-1
    // var res = 0
    // for i in 0..<cnt {
    //     res += (v[idx]*m)
    //     idx += m
    // }
    // 계수정렬 -> O(N)
    var dict = Array(repeating: 0, count: k+1)
    score.forEach{dict[$0]+=1}
    dict = [Int](dict.reversed())
    dict.removeLast()
    var cnt = 0
    var res = 0
    var cur = k
    for i in dict {
        cnt += i
        while(cnt >= m) {
            cnt-=m
            res+=(cur*m)
        }
        cur-=1
    }
    
    return res
}