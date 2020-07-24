let getA = () => {
  Promise.resolved(12);
};

let getB = a => {
  Promise.resolved(a + 12);
};

let getC = b => {
  Promise.resolved(b + 12);
};

module Promise_ = {
  let let_ = Promise.flatMap;
};

module PromiseMap = {
  let let_ = Promise.map;
};

module Zero = {
  Promise.get(
    Promise.flatMap(Promise.flatMap(getA(), a => getB(a)), b => getC(b)), res =>
    Js.log(res)
  );
};

module First = {
  getA()
  ->Promise.flatMap(a => getB(a))
  ->Promise.flatMap(b => getC(b))
  ->Promise.get(res => Js.log(res));
};

module Second = {
  let result = {
    let%Promise_ a = getA();
    let%Promise_ b = getB(a);
    let%PromiseMap c = getC(b);

    c;
  };
};
