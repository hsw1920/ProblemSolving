import Foundation

func solution(_ babbling:[String]) -> Int {
    // 발음할 수 있는 단어의 개수
    // aya ye woo ma -> 연속같은발음 ㄴㄴ, 저거 4개만 가능
    var dict: [String:Int] = ["a":3, "y":2, "w":3,"m":2]
    var h: [String:String] = ["a":"aya", "y":"ye", "w":"woo","m":"ma"]
    var v = babbling.map{$0.map{String($0)}}
    var res = 0
    v.forEach { vv in
        var cur = vv
        var idx = 0
        var cnt = 0
        var chk = 0
        var flag = ""
        cur.forEach { val in
            if cnt > 0 { 
                cnt-=1
                idx+=1
                return 
            }
            guard let k = dict[val] else { 
                idx+=1
                chk=1
                return 
            }
            
            if cur[idx...min(idx+k-1,cur.count-1)].joined() == h[val]!,
                flag != h[val]!
            {
                flag = h[val]!
                cnt+=(k-1)
            } else {
                chk = 1
            }
                     
            idx+=1
        }
        if chk == 0 {
            res+=1
        }
    }
    
    return res
}