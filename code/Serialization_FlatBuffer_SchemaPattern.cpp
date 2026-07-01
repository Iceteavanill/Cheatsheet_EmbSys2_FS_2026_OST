namespace CommunicationObjects;

table CommandMessage { number:int; }
table DataMessage    { ts:int; temp:float; }
union Payload { CommandMessage, DataMessage }

table Message { message:Payload; }
root_type Message;