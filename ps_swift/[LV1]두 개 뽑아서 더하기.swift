import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var k: Set<Int> = []
    var len = numbers.count
    for i in 0..<len-1 {
        for j in i+1..<len {
            k.insert(numbers[i]+numbers[j])
        }
    }
    // var nums: [Int] = []
    // for i in k {
    //     nums.append(i)
    // }
    // nums.sort()
    // return nums
    return k.sorted()
}