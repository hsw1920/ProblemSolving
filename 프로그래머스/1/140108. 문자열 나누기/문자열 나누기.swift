import Foundation

func solution(_ s:String) -> Int {
    // s 입력시 문자열을 분해함
    // 첫글자 x
    // x횟수와 다른 글자가 나온횟수를 세고
    // 처음으로 같아지는 순간 멈추고 읽은 문자열을 분리함.
    var s = s.map{String($0)}
    var ed = s.count-1
    var res = 1
    
    var a = s[0]
    var acnt = 1
    var bcnt = 0
    var flag = 1
    
    if s.count == 1 { return 1 }
    
    for i in 1...ed {
        if flag == 0 {
            a=s[i]
            acnt = 1
            bcnt = 0
            res+=1
            flag=1
            continue
        }
        
        var cur = s[i]
        if cur != a {
            bcnt += 1
        } else {
            acnt += 1
        }
        
        if acnt == bcnt {
            flag = 0
        }
    }
    
    return res
}