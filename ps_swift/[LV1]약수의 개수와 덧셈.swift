import Foundation
func chk(_ num: Int) -> Bool {
    var cnt = 0
    for i in 1...num {
        if num%i == 0 {
            cnt+=1
        }
    }
    return cnt%2==0
}
func solution(_ left:Int, _ right:Int) -> Int {
    var res = 0
    for i in left...right {
        if chk(i) {
            res += i
        }
        else {
            res-=i
        }
    }
    return res
}