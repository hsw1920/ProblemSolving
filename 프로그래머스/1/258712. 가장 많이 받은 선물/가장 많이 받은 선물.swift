import Foundation

func solution(_ friends:[String], _ gifts:[String]) -> Int {
    
    var friendsInfo: [String:Int] = [:]
    for (idx, fri) in friends.enumerated() {
        friendsInfo[fri]=idx
    }
    var give: [[Int]] = [[Int]](repeating: [Int](repeating: 0, 
                                                 count: friends.count), 
                                count: friends.count)
    var giveCount: [Int] = [Int](repeating: 0, count: friends.count)
    for gift in gifts {
        var tmp = gift.split(separator: " ").map{String($0)}
        var from = friendsInfo[tmp[0]]!
        var to = friendsInfo[tmp[1]]!
        give[from][to]+=1
        giveCount[from]+=1
        giveCount[to]-=1
    }
    var ret = 0
    for from in 0..<friends.count {
        var resCount = 0
        
        for to in 0..<friends.count {
            if from == to { continue }
            
            if give[from][to] > give[to][from]
                || (give[from][to] == give[to][from] 
                    && giveCount[from] > giveCount[to])
            {
                resCount+=1
            }
        }
        ret=max(ret,resCount)
    }
    
    return ret
}