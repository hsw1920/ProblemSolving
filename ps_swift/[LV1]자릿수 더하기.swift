import Foundation

func solution(_ n:Int) -> Int
{
    var answer:Int = 0
    var tmp = n
    while(true) {
        answer+=tmp%10
        tmp/=10
        if tmp==0 {
            break
        }
    }
    
    
    
    return answer
}