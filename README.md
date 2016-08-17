# WrapCExample

Ruby wrapper for C example

## Installation

	git clone https://github.com/IDme/wrap_c_example
	cd wrap_c_example
	rake build
	gem install pkg/wrap_c_example-0.0.1.gem
	


## Usage

	$ pry
	[1] pry(main)> require "wrap_c_example"
	=> true
	[2] pry(main)> g = WrapCExample::Greeting.new("Zac")
	=> #<WrapCExample::Greeting:0x007fc36d217e50 @name="Zac">
	[3] pry(main)> g.hello
	=> "Hello Zac! How are you?"

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
