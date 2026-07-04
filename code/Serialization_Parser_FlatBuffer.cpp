// Serializer using flat buffer
flatbuffers::FlatBufferBuilder builder(64); // init builder object with 64b memory
for (auto dp : data) { // loop through datapoints,
    builder.Clear();
    auto datapoint_offset = CommunicationObjects::CreateDataMessage(
            builder, dp.timestamp, dp.temperature); // create flatbuffer object
    builder.Finish(datapoint_offset);
    cp->Transmit(builder.GetBufferPointer(), builder.GetSize());// send object
}