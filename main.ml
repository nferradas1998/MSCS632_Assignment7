let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let a = List.nth sorted (n / 2 - 1) in
    let b = List.nth sorted (n / 2) in
    (float_of_int (a + b)) /. 2.0


let mode lst =
  let freq =
    List.fold_left (fun acc x ->
      let count = try List.assoc x acc with Not_found -> 0 in
      (x, count + 1) :: List.remove_assoc x acc
    ) [] lst
  in
  let max_count = List.fold_left (fun m (_,c) -> if c > m then c else m) 0 freq in
  List.(freq |> filter (fun (_,c) -> c = max_count) |> map fst)


let () =
  let data = [1;2;2;3;4;4;4;5] in
  Printf.printf "Mean:   %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  let modes = mode data in
  Printf.printf "Mode:   ";
  List.iter (fun x -> Printf.printf "%d " x) modes;
  Printf.printf "\n"
