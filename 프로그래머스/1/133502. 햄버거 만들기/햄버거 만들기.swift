import Foundation



func solution(_ ingredient:[Int]) -> Int {
    
    // 빵야채고기빵 -> 1231
    var res = 0
    var top = -1 
    var v = [ingredient[0]]
    var cnt: [Int] = []
    
    if v[0] == 1 { cnt.append(1) } 
    else { cnt.append(0) }
    
    if ingredient.count < 4 { return 0 }
    
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
                
                var tmp = 3
                while tmp > 0 {
                    v.removeLast()
                    cnt.removeLast()
                    tmp -= 1
                }
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