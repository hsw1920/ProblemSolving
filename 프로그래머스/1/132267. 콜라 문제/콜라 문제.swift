import Foundation

func solution(_ a:Int, _ b:Int, _ n:Int) -> Int {
    // 빈병 a개 -> 콜라 b개 줌
    // n개 가져다 주면 몇개 주나?
    
    var res = 0
    var n = n
    while(n>=a) {
        var q = (n/a)*b
        var w = (n%a)
        n /= a
        n*=b
        n += w
        res+=q
    }
    
    return res
}