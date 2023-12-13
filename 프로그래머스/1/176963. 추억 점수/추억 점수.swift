import Foundation

func solution(_ name:[String],
              _ yearning:[Int], 
              _ photo:[[String]]) 
-> [Int] {
    
    var dict: [String:Int] = [:]
    for (idx, item) in name.enumerated() {
        dict[item] = yearning[idx]
    }
    
    var ans: [Int] = []
    
    photo.forEach { item in
        var num: Int = 0
        item.forEach { numb in
            num += dict[numb] ?? 0
        }
        ans.append(num)
    }
    
    return ans
}