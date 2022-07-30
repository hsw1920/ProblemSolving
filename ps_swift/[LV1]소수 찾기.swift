import Foundation

func solution(_ n:Int) -> Int {
    var res = 0;
    for i in 2...n {
        var chk = false
        if i < 4 {
            res+=1
            continue
        }
        //i -> 3 1
        for j in 2...Int(sqrt(Double(i))){
            if i%j==0 {
                chk=true
                break;
            }
        }
        
        if chk == false {
            res+=1
        }
    }

    return res
}