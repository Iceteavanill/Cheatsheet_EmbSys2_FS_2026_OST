// Serializer using flat buffer
flatbuffers::FlatBufferBuilder builder;
auto msg = CommunicationObjects::CreateDataMessage(builder, ts, temp);
builder.Finish(msg);
cp->Transmit(builder.GetBufferPointer(), builder.GetSize());