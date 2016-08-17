require 'spec_helper'

describe WrapCExample do

  it 'should create a new Greeting object' do
    WrapCExample::Greeting.new("Full Name")
  end

  it 'should say hello to `Full Name`' do
    expect(WrapCExample::Greeting.new("Full Name").hello).to eq("Hello Full Name! How are you?")
  end

end
