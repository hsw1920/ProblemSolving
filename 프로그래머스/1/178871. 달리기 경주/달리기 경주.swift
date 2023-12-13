import Foundation

func solution(_ players:[String], _ callings:[String]) -> [String] {
    
    var dict: [String:Int] = [:]
    var num: [Int:String] = [:]
    for (idx,item) in players.enumerated(){
        dict[item]=idx
        num[idx]=item
    }
    
    callings.forEach{
        var th = dict[$0]!
        var name = $0
        
        var to = th-1
        var toName = num[to]!
        
        dict[name]=to
        dict[toName]=th
        num[th]=toName
        num[to]=name
    }
    
    let sortedArr = dict.sorted{$0.value<$1.value}
    let res = sortedArr.map{$0.key}
    
    return res
}