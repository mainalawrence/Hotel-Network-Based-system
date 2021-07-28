var catmodel=
        [
            {
                1:"kimani",
                 2:"maina",
                 3:"mwaning",
                 4:"ken",
                 5:"james"
            }
            ,
            {
                1:"kimani",
                 2:"maina",
                 3:"mwaning",
                 4:"ken",
                 5:"james"
            }
            ,
            {
                "numbers":[{1:"kimani",
                    2:"maina",
                    3:"mwaning",
                    4:"ken",
                    5:"james"}]

            }
        ]

var jsonString = '[{"name":"John","score":51},{"name":"Jack","score":17}]';
var Newdata = JSON.parse(jsonString, function reviver(key, value) {
return key === 'name' ? value.toUpperCase() : value;
});

var testreplacer={1:"car",2:"Two",3:"Three",3:"six",3:"nine",4:"four"}
