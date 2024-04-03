import Foundation



func solution(_ ingredient:[Int]) -> Int {
    var res = 0
    var top = -1 
    var v = [ingredient[0]]
    var cnt: [Int] = []
    
    if v[0] == 1 { cnt.append(1) } 
    else { cnt.append(0) }
    
    for i in 1..<ingredient.count {
        var cur = ingredient[i]
        if v.isEmpty {
            v.append(cur)
            if cur == 1 { cnt.append(1) } 
            else { cnt.append(0) }
            continue
        }
        
        var idx = v.count
        var prev = v[idx-1]
        var prevCnt = cnt[idx-1]
        
        if cur == 1 {
            if prev==3 && prevCnt==3 {
                res += 1
                
                v.removeLast(3)
                cnt.removeLast(3)
            } 
            else {
                v.append(cur)
                cnt.append(1)
            }
        } else {
            if prev==cur-1 {
                cnt.append(prevCnt+1)
            } else {
                cnt.append(0)
            }
            v.append(cur)
        }
    }
    
    return res
}