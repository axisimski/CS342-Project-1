//
// F# program to analyze Divvy daily ride data.
//
// <<Alexander Simeonovski>>
// U. of Illinois, Chicago
// CS 341, Spring 2018
// Project #04
//

#light

let ParseLine (line:string) = 
  let tokens = line.Split(',')
  let ints = Array.map System.Int32.Parse tokens
  Array.toList ints

let rec ParseInput lines = 
  let rides = Seq.map ParseLine lines
  Seq.toList rides



[<EntryPoint>]
let main argv =
  //
  // input file name, then input divvy ride data and build
  // a list of lists --- [ [1308;321;2;1991]; ... ]
  //
  let filename = System.Console.ReadLine()
  let contents = System.IO.File.ReadLines(filename)
  let ridedata = ParseInput contents
 // printfn "%A" ridedata
  let N = List.length ridedata
  printfn "# of rides: %A" N

  let males = List.filter ( fun x -> List.item 2 x=1 ) ridedata
  let females = List.filter ( fun x -> List.item 2 x=2 ) ridedata
  
  printfn "%% of males: %A"  (double(males.Length) / double(N))
  printfn "%% of females: %A"  (double(females.Length) / double(N))

  let durations = List.map(fun sublist -> List.item 1 sublist) ridedata

  printfn "Avg Duration: %A mins" (double(List.sum durations)/(double(60*N))) 

  
  let maleAges = List.map(fun sublist -> List.item 3 sublist) males

  printfn "Average age of male-identified riders is: %A" ((double(males.Length*2018)-double(List.sum maleAges))/double(males.Length)) 
 
  let femaleAges = List.map(fun sublist -> List.item 3 sublist) females

  printfn "Average age of female-identified riders is: %A" ((double(females.Length*2018)-double(List.sum femaleAges))/double(females.Length)) 
 
   
 









  0 
