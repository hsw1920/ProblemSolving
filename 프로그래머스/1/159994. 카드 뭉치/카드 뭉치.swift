import Foundation

func solution(_ cards1:[String], _ cards2:[String], _ goal:[String]) -> String {
    var dict: [String:Int] = [:]
    var idx1 = 0
    var idx2 = 0
    for k in goal {
        if idx1<cards1.count,k == cards1[idx1] {
            idx1+=1
        } else if idx2<cards2.count, k == cards2[idx2] {
            idx2+=1
        } else {
            return "No"
        }
    }
    return "Yes"
}