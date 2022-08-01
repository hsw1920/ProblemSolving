func solution(_ strings:[String], _ n:Int) -> [String] {
    return strings.sorted { (a, b) -> Bool in
        // n번째 String의 index를 비교
        // 같으면 사전순으로 오름차순으로 정렬                           
        if a[String.Index(encodedOffset: n)]  == b[String.Index(encodedOffset: n)] {
            return a < b
        } 
        else {
        // 다르면 n번째 index의 element로 오름차순 정렬
            return a[String.Index(encodedOffset: n)]  < b[String.Index(encodedOffset: n)]
        }
    }
}


// Array 형식으로 표기

// func solution(_ strings:[String], _ n:Int) -> [String] {
//     var result = strings.sorted { (a, b) -> Bool in
//     if Array(a)[n] == Array(b)[n] {
//         return a < b
//     } else {
//         return Array(a)[n] < Array(b)[n]
//     }
//     return a < b
//     }
//     return result
// }