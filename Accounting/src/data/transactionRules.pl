%category(string, name, type, ein).
category('Burger King','Burger King','Meals Expense',_EIN).


%match()/4 Given a memo, can determine if that memo contains a substring that
%indicates the transaction can be autocategorized a certain way.
%fact format supports a memo, name, and type pairing to be tied to 
%all eins, one ein, or multiple eins
match(Memo,Name,Type,EIN) :- category(Condition,Name,Type,EIN), sub_string(Memo, _, _, _, Condition).