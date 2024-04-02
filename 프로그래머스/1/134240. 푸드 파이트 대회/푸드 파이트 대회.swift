import Foundation

func solution(_ food:[Int]) -> String {
    // 칼로리가 적은 순서대로 음식 "수"이 담김
    // food[0]은 물
    // food[i]는 i번의 음식의 수임
    // 물1 ,3개 4개 6개
    // 111 2222 333333
    var str = ""
    for i in 1..<food.count {
        var cur = food[i]/2
        while(cur>0) {
            cur-=1
            str+=String(i)
        }
    }
    
    var ret = str+"0"+String(str.reversed())
    
    return ret
}